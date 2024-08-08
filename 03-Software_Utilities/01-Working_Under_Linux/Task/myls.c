#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <signal.h>

void printPermissions(mode_t fileMode);
void printFileTime(struct stat *fileState);
void printFileOwner(struct stat *fileState);
void printGroupOwner(struct stat *fileState);
void printFileDetails(struct stat *fileState,struct dirent *entry);
void listDirectory(const char *path);
void igonreTerminateSignal();

int main(char argc , char *argv[]){
    igonreTerminateSignal();
    //specify the path of the directory to print its info
    //if a path is not given then print info of current directory
    const char *path= (argc > 1) ? argv[1] : ".";
    listDirectory(path);
}


/**
 * @brief Loop on the directory files and adjust their file path and print each file details
 * 
 * @param path path to the directory to print its details
 */

void listDirectory(const char *path){
    DIR *openDirectory;
    struct dirent *entry;
    char filePath[1024];
    struct stat fileState;
    openDirectory=opendir(path);
    if(openDirectory==NULL){
        perror("Can't open directory");
        exit(EXIT_FAILURE);
    }
    //read each file from the directory and print its details
    while((entry=readdir(openDirectory))!=NULL){
        //skip hidden files
        if(entry->d_name[0]=='.'){
            continue;
        }
        //Adjust file path to get the stat of each file using stat system call
        snprintf(filePath,sizeof(filePath),"%s/%s",path,entry->d_name);
        if (stat(filePath, &fileState) == -1) {
            perror("Can't get state of the file");
            exit(EXIT_FAILURE);
        }
        printFileDetails(&fileState,entry);
    }
}

/**
 * @brief print all file details
 * 
 * @param fileState the state if the file returned from stat system call
 * @param entry the file entry in the directory
 */
void printFileDetails(struct stat *fileState,struct dirent *entry){
    
    printPermissions(fileState->st_mode);
    //print number of hard links
    printf(" %ld\t", fileState->st_nlink);

    printFileOwner(fileState);
    printGroupOwner(fileState);
    //print file size
    printf(" %ld\t",fileState->st_size);

    printFileTime(fileState);
    //print file name
    printf(" %s\n",entry->d_name);  
}

/**
 * @brief print permissions of the file (owner,group,other) and file type
 * 
 * @param fileMode the file mode which contain informations about file type and file permissions
 */
void printPermissions(mode_t fileMode){
    char result[11];
    //check for the type of file and specify the letter of each type 
    if(S_ISREG(fileMode)) result[0]='-';
    else if(S_ISDIR(fileMode)) result[0]='d';
    else if(S_ISCHR(fileMode)) result[0]='c';
    else if(S_ISBLK(fileMode)) result[0]='b';
    else if(S_ISFIFO(fileMode)) result[0]='p';
    else if(S_ISLNK(fileMode)) result[0]='l';
    else if(S_ISSOCK(fileMode)) result[0]='s';
    else{
        perror("File type unkown");
        exit(EXIT_FAILURE);
    }
    //check owner permissions
    result[1] = (fileMode & S_IRUSR) ? 'r' : '-';
    result[2] = (fileMode & S_IWUSR) ? 'w' : '-';
    result[3] = (fileMode & S_IXUSR) ? 'x' : '-';

    //check group permissions
    result[4] = (fileMode & S_IRGRP) ? 'r' : '-';
    result[5] = (fileMode & S_IWGRP) ? 'w' : '-';
    result[6] = (fileMode & S_IXGRP) ? 'x' : '-';

    //check others permissions
    result[7] = (fileMode & S_IROTH) ? 'r' : '-';
    result[8] = (fileMode & S_IWOTH) ? 'w' : '-';
    result[9] = (fileMode & S_IXOTH) ? 'x' : '-';

    result[10] = '\0';

    printf("%s\t",result);
}

/**
 * @brief parse file time and print it in a readable format
 * 
 * @param fileState the state if the file returned from stat system call
 */
void printFileTime(struct stat *fileState){
    struct tm *timeInfo;
    char timebuf[80];
    // get the modification time from the stat of the file and print in readable formal
    timeInfo = localtime(&fileState->st_mtime);
    strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", timeInfo);
    printf(" %s\t", timebuf);
}

/**
 * @brief prine the user name of the file owner
 * 
 * @param fileState the state if the file returned from stat system call
 */
void printFileOwner(struct stat *fileState){
    struct passwd *passwdEntry;
    //get a pointer to entry of the user of the file in /etc/passwd and print its name 
    passwdEntry=getpwuid(fileState->st_uid);
    if(passwdEntry==NULL){
        perror("Can't get username");
        exit(EXIT_FAILURE);
    }
    printf("%s\t",passwdEntry->pw_name);
}

/**
 * @brief print the group name of the file
 * 
 * @param fileState the state if the file returned from stat system call
 */
void printGroupOwner(struct stat *fileState){
    struct group *groupEntry;
    //get a pointer to entry of the group of the file in /etc/group and print its name 
    groupEntry=getgrgid(fileState->st_gid);
    if(groupEntry==NULL){
        perror("Can't get group name");
        exit(EXIT_FAILURE);
    }
    printf("%s\t",groupEntry->gr_name);
}
/**
 * @brief function ignore kill -15 signal and do nothing
 * 
 */
void igonreTerminateSignal(){   
    struct sigaction action;
    // ignore the signal coming
    action.sa_handler=SIG_IGN;
    sigemptyset(&action.sa_mask);
    action.sa_flags=0;
    // specify terminate signal to ignore it
    if (sigaction(SIGTERM, &action, NULL)==-1) {
        perror("Can't modify signal action");
        exit(EXIT_FAILURE);
    }
}
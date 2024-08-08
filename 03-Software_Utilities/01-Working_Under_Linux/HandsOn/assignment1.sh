#!/bin/bash

ls /bin/*.sh

cd /home/adham/Siemens-SW-Diploma/03-Software_Utilities/01-Working_Under_Linux/HandsOn/UNXclass/

mkdir -p Letters Programs Misc

cp *let* Letters/

cp *.[ch] Programs/

cp *notes* *misc* Misc/

mkdir -p UStoreIt

cp copy.me* UStoreIt/

mv move.me* UStoreIt/

rm *del*



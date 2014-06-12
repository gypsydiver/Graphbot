//
//  ResourcesPath.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/4/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

#ifndef Graphbot_ResourcesPath_h
#define Graphbot_ResourcesPath_h

#include "CoreFoundation/CoreFoundation.h"

//path variable
char path[PATH_MAX];

//if user sets Graphbot.app too deep and the path exceeds 1024 characters failure will be upon us
void loadResourcesPath(){
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    
    if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX)){
        //error, we should probably do something about this
        std::cout<< "Failed loading resources path :("<<std::endl;
    }
    CFRelease(resourcesURL);
    chdir(path);
    //char cd [PATH_MAX]= "cd ";
    //system(strcat(cd,path));
    //system("ls");
}


#endif

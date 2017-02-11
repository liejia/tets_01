#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "mxml.h"

int main(int argc, const char* argv[])
{
    FILE* fp = fopen("index.html", "r");
    if(fp == NULL){
        perror(" error");
        exit(1);
    }
    mxml_node_t* node, *title, *p;
    char* s1;
    node = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);
    title = mxmlFindElement(node, node, "title", NULL, NULL, MXML_DESCEND);
    printf("title text:%s\n", mxmlGetText(title, NULL));
    p = mxmlFindElement(node, node, "p", "style", NULL, MXML_DESCEND);
    if(p == NULL){
        printf("p not found\n");
    }else{
        printf("p style:%s\n", mxmlElementGetAttr(p, "style"));
    }
    mxmlDelete(node);
    fclose(fp);
    return 0;
}

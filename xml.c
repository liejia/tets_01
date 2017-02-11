#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <mxml.h>

int main(int argc, const char* argv[])
{
    FILE* fp = fopen("test.xml", "w");
    if(fp == NULL)
    {
        perror(" error");
        exit(1);
    }   

    mxml_node_t* node, *node_1, *node__1;
    node = mxmlNewXML("1.0");

    node_1 = mxmlNewElement(node, "class");
    mxmlElementSetAttr(node_1, "name", "C++就业班"); 


    node__1 = mxmlNewElement(node_1, "monitor");

    mxmlNewElement(node__1, "name");
    mxmlNewText(node__1, 0, "罗玉龙");
    mxmlNewElement(node__1, "sex");
    mxmlNewText(node__1, 0, "男");


    int n = mxmlSaveFile(node, fp, MXML_TEXT_CALLBACK);
    
    mxmlDelete(node);
    mxmlDelete(node_1);
    mxmlDelete(node__1);

    
    fclose(fp);


    return 0;
}

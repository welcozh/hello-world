#include "XmlNodeWrapper.h"
#include <string>
#include <iostream>

using namespace std;

char* getNodeString(xmlDocPtr pdoc, xmlChar* xpath, int i)
{
    CXmlNodeWrapper xmlnodewrapper; 
    xmlXPathObjectPtr app_result = getNodeset(pdoc, xpath); 
    xmlNodePtr xmlnode = xmlnodewrapper.Node(app_result, i);

    char* str = xmlnodewrapper.getNodeTest(xmlnode);
    //xmlFree(xmlnode);
    return str;
}

xmlChar* getNodeProp(xmlDocPtr pdoc, xmlChar* xpath, xmlChar* prop, int i)
{
    CXmlNodeWrapper xmlnodewrapper;
    xmlXPathObjectPtr result = getNodeset(pdoc, xpath);
    xmlNodePtr xmlnode = xmlnodewrapper.Node(result, i);
    xmlChar* str = xmlGetProp(xmlnode, prop);
    //xmlFree(xmlnode);
    return str;

}

int main(int argc, char **argv)
{
    CXmlNodeWrapper xmlnodewrapper;

    xmlDocPtr pdoc;
    pdoc = readFile("run_sentinel.xml");

    xmlNodePtr proot = NULL;
    proot = xmlDocGetRootElement(pdoc);
    if(proot == NULL)
    {
        printf("error: file is empty!\n");
        exit(1);
    
    }
    
    xmlChar* xpath = BAD_CAST("//process/io/parameter");

    xmlXPathObjectPtr app_result = getNodeset(pdoc, xpath);
    xmlNodeSetPtr nodeset = app_result->nodesetval;
    int N = nodeset->nodeNr;

    printf("N=%d\n", N);

    xpath = BAD_CAST("//process");
    app_result = getNodeset(pdoc, xpath);
    nodeset = app_result->nodesetval;
    int stepnum = nodeset->nodeNr;
    
    string table[10] = {"Sentinel-1A-Converting", "Sentinel-1-Updating", "Sentinel-1-SubswathSplit", "Sentinel-1-DcPara", "Sentinel-1-DerampPhase", 
                        "Sentinel-1-S1Deramp", "Sentinel-1-S1DemReg", "Sentinel-1-S1Reramp", "Sentinel-1-S1BurstSplice", "Sentinel-1-S1Merge"};

    for(int i=0;i<N;i++)
    {
        xpath = BAD_CAST("//process/io/parameter");
        char* temp = getNodeString(pdoc, xpath,i);
        printf("%d: %s\n", i, temp); 
    }

    /*int stepnum = 0;
    
    xmlChar* xpath = BAD_CAST("//process");
    xmlChar* desc = getNodeProp(pdoc, xpath, BAD_CAST("desc"), 0);
    
    while(desc!=NULL)
    {
        printf("%s\n", desc);
        stepnum++;
        desc = getNodeProp(pdoc, xpath, BAD_CAST("desc"),stepnum);
    }

    //stepnum -= 1;
*/
    printf("%d\n",stepnum);

    
    /*xmlNodeSetPtr nodeset = app_result->nodesetval;
    string ioset[];

    for(int i=0;i<;i++)//run_sentinel.xml step:1-10 
    {
        xmlChar* xpath = BAD_CAST("//process");
        xmlChar* desc = getNodeProp(pdoc, xpath, BAD_CAST("desc"), i);
        xmlChar* iochar = getNodeProp(pdoc, xpath, BAD_CAST("iocount"), i);
        
        int iocount = atoi((char*)iochar);
        
        for(int j=0;j<iocount;j++){
            xpath = BAD_CAST("/process/io");
            xmlXPathObjectPtr re = getNodeset(pdoc, xpath);
            xmlNodePtr cur = xmlnodewrapper.Node(re, j);
        }
    }
    */
    xmlFree(proot);
    xmlFreeDoc(pdoc);
    xmlCleanupParser();
    xmlMemoryDump();

    return 1;

}

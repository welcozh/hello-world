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
    xmlDocPtr pdoc;
    pdoc = readFile("1.xml");

    xmlNodePtr proot = NULL;
    proot = xmlDocGetRootElement(pdoc);
    if(proot == NULL)
    {
        printf("error: file is empty!\n");
        exit(1);
    }

    xmlChar* xpath = BAD_CAST("//numberOfLines");
    char* str = getNodeString(pdoc, xpath, 0);
    printf("%s\n", str);

  
    xpath = BAD_CAST("//rangeSamplingRate");
    str = getNodeString(pdoc, xpath, 0);
    printf("%s\n", str);
    
    xpath = BAD_CAST("//ellipsoidSemiMinorAxis");
    str = getNodeString(pdoc, xpath, 0);
    printf("%s\n", str);
    
    xpath = BAD_CAST("//orbitList");
    xmlChar* temp = getNodeProp(pdoc, xpath, BAD_CAST("count"), 0);

    printf("%s\n", (char*)temp);
   
    xpath = BAD_CAST("//orbitList/orbit/time");
    for (int i=0;i<16;i++){
        str = getNodeString(pdoc, xpath, i);
        printf("%s\n", str);
    }
    string t=str;
    cout << t << endl;

    xmlFree(proot);
    xmlFreeDoc(pdoc);
    xmlCleanupParser();
    xmlMemoryDump();

    return 1;

}

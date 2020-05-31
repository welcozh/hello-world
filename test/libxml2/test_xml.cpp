#include <stdio.h>
#include <stdlib.h>
#include "libxml/parser.h"
#include "libxml/tree.h"
#include "libxml/xpath.h"

using namespace std;

xmlDocPtr readFile(const char* path)
{
    xmlDocPtr pdoc = NULL;
    xmlKeepBlanksDefault(0);

    pdoc = xmlReadFile(path, "UTF-8", XML_PARSE_RECOVER);

    if(pdoc == NULL)
    {
        printf("error: can't open xml file!\n");
        exit(1);
    }

    return pdoc;
}


static xmlXPathObjectPtr getNodeset(xmlDocPtr doc, const xmlChar *xpath) 
{
    xmlXPathContextPtr context;
    xmlXPathObjectPtr result;
    
    context = xmlXPathNewContext(doc);

    if(context == NULL)
    {
        printf("context is NULL\n");
        return NULL;
    }

    result = xmlXPathEvalExpression(xpath, context);
    xmlXPathFreeContext(context);
   
    if(result == NULL)
    {
        printf("xmlXPathEvalExpression return NULL\n");
        return NULL;
    
    }

    if(xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        printf("nodeset is empty\n");
        return NULL;
    }    

    return result; 
} 





int main(int argc, char **argv)
{
    xmlDocPtr pdoc;
    pdoc = readFile("run_sentinel.xml");
    
    xmlNodePtr proot = NULL;
    proot = xmlDocGetRootElement(pdoc);
    if(proot == NULL)
    {
        printf("error: file is empty!\n");
        exit(1);
    }

	xmlChar *xpath = BAD_CAST("/batching/process/io");
    
    xmlXPathObjectPtr app_result = getNodeset(pdoc, xpath);
    if(app_result == NULL)
    {
        printf("app_result is NULL\n");
        return 0;
    }

    int i=0;
    xmlChar *value;
 
    if(app_result)
    {
        xmlNodeSetPtr nodeset = app_result->nodesetval;
        xmlNodePtr cur;

        for(i=0;i<nodeset->nodeNr;i++)
        {
            cur = nodeset->nodeTab[i];
            cur = cur->xmlChildrenNode;

            while(cur != NULL)
            {
                printf("%s\n", ((char*)XML_GET_CONTENT(cur->xmlChildrenNode)));
                
                cur = cur->next;
            }
        }
        xmlXPathFreeObject(app_result);
    }

    xmlFreeDoc(pdoc);
    xmlCleanupParser();
    xmlMemoryDump();

    return 0;
}

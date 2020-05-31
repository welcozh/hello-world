#include "XmlNodeWrapper.h"



CXmlNodeWrapper::CXmlNodeWrapper()
{
}

CXmlNodeWrapper::~CXmlNodeWrapper()
{
}

xmlNodePtr CXmlNodeWrapper::Node(xmlXPathObjectPtr result, int i)
{
    if(result==NULL)
    {
        printf("xmlXPathObject is NULL!\n");
        return NULL;
    }

    xmlNodeSetPtr nodeset = result->nodesetval;
    xmlNodePtr cur;

    cur = nodeset->nodeTab[i];

    return cur;
}

char* CXmlNodeWrapper::getNodeTest(xmlNodePtr cur)
{
    return ((char*)XML_GET_CONTENT(cur->xmlChildrenNode));
}


CXmlNodeListWrapper::CXmlNodeListWrapper()
{
}

CXmlNodeListWrapper::~CXmlNodeListWrapper()
{
}

xmlNodePtr CXmlNodeListWrapper::NodeList(xmlXPathObjectPtr result, int i)
{
    if(result==NULL)
    {
        printf("xmlXPathObject is NULL!\n");
        return NULL;
    }

    xmlNodeSetPtr nodeset = result->nodesetval;
    xmlNodePtr cur;

    cur = nodeset->nodeTab[i];

    return cur;
}

char* CXmlNodeListWrapper::getNodeListTest(xmlNodePtr cur, int i)
{
    if(cur==NULL)
    {
        printf("Node is NULL!\n");
        return NULL;
    }

    int j=0;
    while(cur!=NULL)
    {
        cur = cur->xmlChildrenNode;
        if(i == j)
        {
            return((char*)XML_GET_CONTENT(cur->xmlChildrenNode));
        }
        j++;
    }

    if(j < i)
    {
        printf("The index is out of range!\n");
        return NULL;
    }

}


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


xmlXPathObjectPtr getNodeset(xmlDocPtr doc, const xmlChar *xpath) 
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


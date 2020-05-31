#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "libxml/parser.h"
#include "libxml/tree.h"
#include "libxml/xpath.h"


class CXmlNodeWrapper
{
    public:
        xmlNodePtr Node(xmlXPathObjectPtr result, int i);
        char* getNodeTest(xmlNodePtr cur);
        CXmlNodeWrapper();
        virtual ~CXmlNodeWrapper();
};

class CXmlNodeListWrapper
{
    public:
        xmlNodePtr NodeList(xmlXPathObjectPtr result, int i);
        char* getNodeListTest(xmlNodePtr cur, int i);
        CXmlNodeListWrapper();
        virtual ~CXmlNodeListWrapper();
};

xmlDocPtr readFile(const char* filename);
xmlXPathObjectPtr getNodeset(xmlDocPtr doc, const xmlChar *xpath);


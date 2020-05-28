#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc,char **argv)
{
	xmlDocPtr doc = NULL;/*document pointer*/
	xmlNodePtr root_node = NULL,node = NULL,node1 = NULL;/*node pointers*/

	doc = xmlNewDoc(BAD_CAST"1.0");
	root_node = xmlNewNode(NULL,BAD_CAST"root");
	xmlDocSetRootElement(doc,root_node);
	//creates a new node,which is "attached" as child node of root_node node.
	xmlNewChild(root_node,NULL,BAD_CAST"node1",BAD_CAST"content of node1");

	//xmlNewProp()creates attributes,which is "attached" to an node.
	node = xmlNewChild(root_node,NULL,BAD_CAST"node3",BAD_CAST"node has attributes");
	xmlNewProp(node,BAD_CAST"attribute",BAD_CAST"yes");

	//Here goes another way to create nodes.
	node = xmlNewNode(NULL,BAD_CAST"node4");
	node1 = xmlNewText(BAD_CAST"other way to create content");

	xmlAddChild(node,node1);
	xmlAddChild(root_node,node);

	//Dumping document to stdio or file
        xmlSaveFormatFileEnc(argc > 1 ? argv[1]:"-",doc,"UTF-8",1);
	/*free the document*/
	xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();//debug memory for regression tests

        return 0;
}

void dinsert(node_pointer node, node_pointer newnode)
{
	newnode->llinke = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

void DBdeleted(node_pointer node, node_pointer deleted)
{
	if (node==deleted)
		printf
}
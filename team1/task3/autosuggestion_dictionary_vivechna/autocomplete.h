#include<vector>
using namespace std;

#define SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
vector<string>c;
int i=0;

struct trie_node
{
    struct trie_node *children[SIZE];

    bool isEOW;
};

struct trie_node *getNode(void)
{
    struct trie_node *pNode = new trie_node;
    pNode->isEOW = false;

    for (int i = 0; i < SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct trie_node *root,  const string key)
{
    struct trie_node *curr_node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = CHAR_TO_INDEX(key[i]);
        if (!curr_node->children[index])
            curr_node->children[index] = getNode();

        curr_node = curr_node->children[index];
    }

    curr_node->isEOW = true;
}

bool search(struct trie_node *root, const string key)
{
    int length = key.length();
    struct trie_node *curr_node = root;
    for (int i = 0; i < length; i++)
    {
        int index = CHAR_TO_INDEX(key[i]);

        if (!curr_node->children[index])
            return false;

        curr_node = curr_node->children[index];
    }

    return (curr_node != NULL && curr_node->isEOW);
}

bool isLastNode(struct trie_node* root)
{
    for (int i = 0; i < SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

void suggestions(struct trie_node* root, string prefix)
{
    if (root->isEOW)
    {
        cout << i+1<<":"<<prefix;
        c.push_back(prefix);
        cout << endl;
        i++;
    }

    if (isLastNode(root))
        return;

    for (int i = 0; i < SIZE; i++)
    {
        if (root->children[i])
        {
            prefix.push_back(97 + i);

            suggestions(root->children[i], prefix);
        }
    }
}

int print_suggestions(trie_node* root, const string query)
{
    struct trie_node* curr_node = root;

    int i;
    int n = query.length();
    for (i = 0; i < n; i++)
    {
        int index = CHAR_TO_INDEX(query[i]);

        if (!curr_node->children[index])
            return 0;

        curr_node = curr_node->children[index];
    }

    bool isWord = (curr_node->isEOW == true);

    bool isLast = isLastNode(curr_node);

    if (isWord && isLast)
    {
        cout << query << endl;
        return -1;
    }

    if (!isLast)
    {
        string prefix = query;
        suggestions(curr_node, prefix);
        return 1;
    }
}

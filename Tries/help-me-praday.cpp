#include<stdio.h>
#include<stdlib.h>
 
char ans[200001];
 
typedef struct trie_t {
	struct trie_t* child[26];
	int leaf;
} trie_t;
 
int myStrlen(char* str) {
	int len = 0;
	while(str[len])
		len++;
	return len;
}
 
trie_t* getNode() {
	trie_t* newNode;
	int i;
 
	newNode = (trie_t*) malloc(sizeof(trie_t));
	newNode->leaf = 0;
 
	for(i=0; i<26; i++)
		newNode->child[i] = NULL;
 
	return newNode;
}
 
void insert(trie_t* root, char* str) {
	int len = myStrlen(str), i;
	trie_t* pcrawl = root;
 
	for(i=0; i<len; i++) {
		int x;
		if(str[i] >= 'A' && str[i] <= 'Z') {
			x = str[i] - 'A';
		}
		else
			x = str[i] - 'a';
 
		if(pcrawl->child[x] == NULL) {
			pcrawl->child[x] = getNode();
		}
		pcrawl = pcrawl->child[x];
	}
 
	pcrawl->leaf = 1;
}
 
void triePrint(trie_t* pcrawl, int idx) {
	int i;
 
	if(pcrawl->leaf) {
		ans[idx] = '\0';
		puts(ans);
	}
 
	for(i=0; i<26; i++) {
		if(pcrawl->child[i] == NULL)
			continue;
 
		ans[idx] = 'a' + i;
		triePrint(pcrawl->child[i], idx+1);
	}
}
 
int search(trie_t* root, char* str) {
	int len = myStrlen(str), i;
	trie_t* pcrawl = root;
 
	for(i=0; i<len; i++) {
		int x;
		if(str[i] >= 'A' && str[i] <= 'Z') {
			x = str[i] - 'A';
		}
		else
			x = str[i] - 'a';
 
		if(pcrawl->child[x] == NULL)
			return 0;
		ans[i] = str[i];
		pcrawl = pcrawl->child[x];
	}
	triePrint(pcrawl, i);
	return 1;
}
 
int main() {
 
	int n, i=0, q;
	char str[200001];
	trie_t* root = getNode();
 
	scanf("%d", &n);
 
	for(i=0; i<n; i++) {
		scanf("%s", str);
		insert(root, str);
	}
 
	scanf("%d", &q);
 
	for(i=0; i<q; i++) {
		scanf("%s", str);
		if(!search(root, str)) {
			insert(root, str);
			puts("No suggestions");
		}
	}
 
	return 0;
}

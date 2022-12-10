#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int MAX = 101;

int n;
string str;

struct HTreeNode {
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
};

struct NodeType {
	int no;
	char data;
	int weight;
	bool operator< (const NodeType& s) const {
		return s.weight < weight;
	}
};

HTreeNode ht[MAX];
map<char, string> htcode;

void init () {
	int i;
	map<char, int> mp;
	for (i = 0; i < str.length(); i++) {
		mp[str[i]]++;
	}
	n = mp.size();
	i = 0;
	for ( map<char, int>::iterator it = mp.begin(); it != mp.end(); it++, i++) {
		ht[i].data = it->first;
		ht[i].weight = it->second;
	}
	for (int j = 0; j < 2 * n - 1; j++) {
		ht[j].lchild = ht[j].rchild = ht[j].parent = -1;
	}
}

void create_HTree() {
	NodeType e, e1, e2;
	priority_queue<NodeType> qu;
	for (int i = 0; i < n; i++) {
		e.no = i;
		e.data = ht[i].data;
		e.weight = ht[i].weight;
		qu.push(e);
	}
	for (int i = n; i < 2 * n - 1; i++) {
		e1 = qu.top();
		qu.pop();
		e2 = qu.top();
		qu.pop();
		ht[i].weight = e1.weight + e2.weight;
		ht[i].lchild = e1.no;
		ht[i].rchild = e2.no;
		ht[e1.no].parent = i;
		ht[e2.no].parent = i;
		e.no = i;
		e.weight = e1.weight + e2.weight;
		qu.push(e);
	}
}

void create_HCode () {
	string code;
	code.reserve(MAX);
	for (int i = 0; i < n; i++) {
		code = "";
		int cur_no = i;
		int f = ht[cur_no].parent;
		while (f != -1) {
			if (ht[f].lchild == cur_no) {
				code += '0';
			} else {
				code += '1';
			}
			cur_no = f;
			f = ht[cur_no].parent;
		}
		htcode[ht[i].data] = code;
	}
}

void display() {
	for (map<char, string>::iterator it = htcode.begin(); it != htcode.end(); ++it) {
		cout << "\t" << it->first << ": " << it->second << endl;
	}
}

void encode(string str, string& enstr) {
	for (int i = 0; i < str.length(); i++) {
		enstr = enstr + htcode[str[i]];
	}
}

void decode(string enstr, string& destr) {
	int r = 2 * n - 2, p;
	int i = 0;
	while (i < enstr.length()) {
		p = r;
		while (true) {
			if (enstr[i] == '0') {
				p = ht[p].lchild;
			} else {
				p = ht[p].rchild;
			}
			if (ht[p].lchild == -1 && ht[p].rchild == -1) {
				break;
			}
			i++;
		}
		destr = destr + ht[p].data;
		i++;
	}
}

int main() {
	str = "The following code computes thr intersection of two arrays";
	init();
	create_HTree();
	create_HCode();
	printf("¹þ·òÂü±àÂë£º\n");
	display();
	string enstr = "";
	encode(str, enstr);
	printf("±àÂë½á¹û£º\n");
	cout << enstr << endl;
	string destr = "";
	decode(enstr, destr);
	printf("½âÂë½á¹û£º\n");
	cout << destr << endl;
	return 0;
}

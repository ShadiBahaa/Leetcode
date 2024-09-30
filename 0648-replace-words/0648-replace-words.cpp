class Solution {
public:
    class trie
{
private:
    static const int MAX_CHAR = 26;
    trie *child[MAX_CHAR];
    bool isLeaf{};

public:
    trie()
    {
        // set an array to 0s. Here pointers to null
        memset(child, 0, sizeof(child));
    }

    void insert(string str, int idx = 0)
    {
        if (idx == (int)str.size())
            isLeaf = 1;
        else
        {
            int cur = str[idx] - 'a';
            if (child[cur] == 0)
                child[cur] = new trie();
            child[cur]->insert(str, idx + 1);
        }
    }
    string first_word_prefix(const string &str)
    {
        trie *cur = this;
        string ans = "";
        for (char c : str)
        {

            if (cur->child[c - 'a'])
            {
                ans += c;
                cur = cur->child[c - 'a'];
                if (cur->isLeaf)
                {
                    return ans;
                }
            }
            else
            {
                return str;
            }
        }
        return ans;
    }
    void insert_iter(string str)
    {
        trie *cur = this;
        for (char c : str)
        {
            if (!cur->child[c - 'a'])
            {
                cur->child[c - 'a'] = new trie();
            }
            cur = cur->child[c - 'a'];
        }
        cur->isLeaf = true;
    }
    bool word_exist_iter(string str)
    {
        trie *cur = this;
        for (char c : str)
        {
            if (!cur->child[c - 'a'])
            {
                return false;
            }
            cur = cur->child[c - 'a'];
        }
        return cur->isLeaf;
    }
    bool word_exist(string str, int idx = 0)
    {
        if (idx == (int)str.size())
            return isLeaf; // there is a string marked here

        int cur = str[idx] - 'a';
        if (!child[cur])
            return false; // such path don't exist

        return child[cur]->word_exist(str, idx + 1);
    }

    bool prefix_exist(string str, int idx = 0)
    {
        if (idx == (int)str.size())
            return true; // all subword covered

        int cur = str[idx] - 'a';
        if (!child[cur])
            return false; // such path don't exist

        return child[cur]->prefix_exist(str, idx + 1);
    }
};
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie tree;
        for (string s: dictionary){
            tree.insert(s);
        }
        string ans;
        string tmp;
        for (char c : sentence){
            if(c==' '){
               ans += tree.first_word_prefix(tmp)+ " ";
               tmp = "";
            }else {
                tmp += c;
            }
        }
        if (tmp.size()){
            ans += tree.first_word_prefix(tmp);
        }
        return ans;
    }
};
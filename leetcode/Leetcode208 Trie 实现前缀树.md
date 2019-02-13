# Leetcode208 Trie 实现前缀树

### 题目

实现一个 Trie (前缀树)，包含 `insert`, `search`, 和 `startsWith` 这三个操作。

### 分析

- 字典树关键在于节点的结构的设定。利用字符串的公共前缀节省空间。

- 节点结构应该需要一个节点指针数组代表路径。一个变量记录是否是叶子。

- **拓展**增加数量的记录，需要增加经过该节点的字符串数量和以其为结尾的数量。

- 节点结构如下

  ```c++
  struct TrieNode{
      TrieNode* child[26];
      bool is_end;
      TrieNode():is_end(false){
          for(int i = 0; i < 26; ++i){
              child[i] = 0;
          }
      }
  };
  ```

- 主要需要实现插入，查找，查找前缀等功能。后续可以加上删除功能。

  

  ### 解题代码

  ```c++
  // 关键是前缀树的结构体的设置。具有一个指针数组。可以使用map<char, TrieNode*>。包含一个变量代表是否是叶子节点。
  // 如果要记录数量的话，应该需要一个变量记录path。
  struct TrieNode{
      TrieNode* child[26];
      bool is_end;
      TrieNode():is_end(false){
          for(int i = 0; i < 26; ++i){
              child[i] = 0;
          }
      }
  };
  class Trie {
  public:
      /** Initialize your data structure here. */
      Trie(): root_(new TrieNode()) {
          
      }
      
      /** Inserts a word into the trie. */
      void insert(string word) {
          TrieNode* node = root_;
          for(size_t i = 0; i < word.size(); ++i){
              int pos = word[i] - 'a';
              if(node->child[pos] == 0){
                  node->child[pos] = new TrieNode();
              }
              node = node->child[pos];
          }
          node->is_end = true;
      }
      
      /** Returns if the word is in the trie. */
      // 要是最后一个才行。
      bool search(string word) {
          TrieNode* node = root_;
          for(size_t i = 0; i < word.size(); ++i){
              int pos = word[i] - 'a';
              if(node->child[pos] == 0){
                  return false;
              }
              node = node->child[pos];
          }
          return node->is_end;
      }
      
      /** Returns if there is any word in the trie that starts with the given prefix. */
      bool startsWith(string prefix) {
          TrieNode* node = root_;
          for(size_t i = 0; i < prefix.size(); ++i){
              int pos = prefix[i] - 'a';
              if(node->child[pos] == 0){
                  return false;
              }
              node = node->child[pos];
          }
          return true;
      }
      
  private:
      TrieNode* root_;
  };
  
  /**
   * Your Trie object will be instantiated and called as such:
   * Trie obj = new Trie();
   * obj.insert(word);
   * bool param_2 = obj.search(word);
   * bool param_3 = obj.startsWith(prefix);
   */
  ```

  ### 字典树的应用

  1. 字典树是一种用于快速检索的多叉树结构，如英文字母的字典树是一个26叉树，数字的字典树是一个10叉树。他的核心思想是空间换时间，空间消耗大但是插入和查询有着很优秀的时间复杂度。

  2. 可以用字典树统计前缀出现次数。节点使用一个count记录出现次数。

  3. 输入自动保存。以字符串结尾为root进行先根遍历。先根遍历时需要使用一个数据结构来记录前面出现了的字符。

  4. 如果要查找的关键字可以分解成字符序列且不是很长，利用trie树查找速度优于二叉查找树。

  5. [Trie树：应用于统计和排序](https://blog.csdn.net/hguisu/article/details/8131559)

     

  

  

  

  


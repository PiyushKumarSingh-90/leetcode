/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void DFS(Node* node, Node* clone_node, vector<Node*>& visited) 
    {
        visited[node->val] = clone_node;
        
        for(Node* x : node->neighbors) 
        {
            if(visited[x->val] == NULL) 
            {
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone, visited);
            } 
            else 
            {
                clone_node->neighbors.push_back(visited[x->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, clone its neighbours and recursively their neighbours
        /*
            But if a node reappears, then we need to access that cloned node
            So, store them in a vector to access
        */
        
        vector<Node*> visited(101, NULL); //Using contraints given
        //We could use map also if constraints are not clear (i.e. unordered_map<Node*, Node*> visited;)
        visited[node->val] = clone_node;
        

        DFS(node, clone_node, visited);
 
        
        
        return clone_node;
    }
};
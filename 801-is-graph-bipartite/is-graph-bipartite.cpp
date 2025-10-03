class Solution {
public:
bool check(vector<vector<int>>& adj,int u,vector<int>& color,int currcol){
      color[u]=currcol; // color kardiya current node ko 
      // ab jate hai adjacent nodes par 
      for(int &v:adj[u]){
          if(color[v]==color[u])
          return false;
          if(color[v]==-1) {
              //never coloured
              int colorofv=1-currcol;
              if(check(adj,v,color,colorofv)==false)
              return false;
          }
      }
      return true;
  }
    bool isBipartite(vector<vector<int>>& adj) {
        //red =1;
        //green =0;
        int v=adj.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(check(adj,i,color,1)==false)
                return false;
            }
        }
        return true;    
    }
};
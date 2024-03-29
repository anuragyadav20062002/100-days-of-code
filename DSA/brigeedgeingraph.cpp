class Solution{
    
    static void DFS(int s,ArrayList<ArrayList<Integer>> adj,boolean[] visited){
        visited[s]=true;
        for(int u:adj.get(s)){
            if(!visited[u]){
                DFS(u,adj,visited);
            }
        }
    }
    //Idea : To remove edge from the graph adj list 
    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj,int c,int d){
        
        if(c>=V && d>=V && c<0 && d<0){
            return 0;
        }
        
        boolean[] visited=new boolean[V];
        int count=0;
        //counting number of connected components in original graph
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                count++;
                DFS(i,adj,visited);
            }
        }
        
        adj.get(c).remove(Integer.valueOf(d));
        adj.get(d).remove(Integer.valueOf(c));
        
        Arrays.fill(visited,false);
        int count2=0;
        //counting number of connected components in modified graph
        //if found extra component then return true
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFS(i,adj,visited);
                count2++;
            }
            if(count2>count){
                return 1;
            }
        }
        
        return 0;
        
    }
}
class Solution {
    public List<Integer> levelOrder(TreeNode root) {
    List<Integer> levels = new ArrayList<Integer>();
    if (root == null) return levels;

    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    int level=0,flag=0;
    while ( flag==1 ) {
      flag=0;
…                flag=1;
            }
            else queue.add(null);
        }
      }
      level++;
    }
    return levels;
    }
    
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int idx1=0,idx2=0;
        List<Integer> levels = new ArrayList<Integer>();
        levels=levelOrder(root);
        for(int i=0;i<levels.size();i++){
            if(levels.get(i)==p.val){
                idx1=i+1;
            }
            if(levels.get(i)==q.val){
                idx2=i+1;
            } 
        }
        List<Integer> tmp = new ArrayList<Integer>();
        while(idx2>0){
            tmp.add(idx2);
            idx2=idx2/2;
        }
        while(idx1>0){
            if(tmp.contains(idx1)){
                TreeNode ans=root;
                List<Integer> tmp1 = new ArrayList<Integer>();
                int steps=idx1;
                while(steps>1){
                    if(steps%2==1){
                        tmp1.add(1);
                    }
                    else{
                        tmp1.add(0);
                    }
                for(int i=tmp1.size()-1;i>=0;i--){
            if(tmp1.get(i)==1)
                ans=ans.right;
            else
                ans=ans.left;
        }
        return ans;
        }
        idx1=idx1/2;
        }
        return root;
        }
}
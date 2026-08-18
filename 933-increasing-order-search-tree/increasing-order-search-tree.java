/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

class Solution {
    public TreeNode increasingBST(TreeNode root) {

        Stack<TreeNode> stack = new Stack<>();

        TreeNode current = root;

        TreeNode dummy = new TreeNode(0);
        TreeNode tail = dummy;

        while (current != null || !stack.isEmpty()) {

            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();

            TreeNode right = current.right;

            current.left = null;

            tail.right = current;
            tail = current;

            current = right;
        }

        return dummy.right;
    }
}
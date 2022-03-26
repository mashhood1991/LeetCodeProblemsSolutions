class Solution {
public:
    string removeDuplicates(string s) {
/*        
//stack is very helpful in problems where you have to remove some part out and the then the remaining parts you have to concatenate
//stack is LIFO data structure
        

The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the top most element of the stack – Time Complexity : O(1) 
*/
        //second solution: using range based for loop      
        //stack ds to store the ch
        stack<char> st;
        
        for(char& c : s) //here c is referencing to s
        {
            if(st.size()>0 && st.top()==c)
                st.pop();
            else
                st.push(c);
        }
        
        //define an empty string to store the stack results into string
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;  
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int i=0;
        size_t slash=path.find('/', 0);
        //i = slash;
        while(1){
            string cur;
            i = slash;
            slash = path.find('/', i+1);
            cur = path.substr(i, slash-i);
            if(slash == string::npos){
                cur = path.substr(i, path.length()-i);
            }
            if(cur != "/." && cur!="/"){
                if((stack.empty() || stack.back()!=cur) && (cur!="/.."))   stack.push_back(cur);
                else{
                    if(!stack.empty())  stack.pop_back();
                }
            }
            if(slash == string::npos) break;
        }
        if(stack.empty()) return "/";
        else{
            string res="";
            for(int i=0; i<stack.size(); i++)   res += stack[i];
            return res;
        }
    }
};
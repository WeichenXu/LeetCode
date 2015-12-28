class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        vector<string> preCombinations;
        for(int i=0; i<digits.length(); i++){
            int digit = digits[i]-'0';
            if(digit < 2){
                combinations.clear();
                return combinations;
            }
            else{
                switch (digit){
                case 7:
                    preCombinations = combinations;
                    combinations.clear();
                    if(!preCombinations.size()){
                        for(int i=0; i<4; i++){
                            string add = "";
                            add.append(1, 'p'+i);
                            combinations.push_back(add);
                        }
                    }
                    else{
                        for(int j=0; j<preCombinations.size(); j++){
                            for(int i=0; i<4; i++){
                                string add = preCombinations[j];
                                add.append(1, 'p'+i);
                                combinations.push_back(add);
                            }
                        }
                    }
                    break;
                case 8:
                    preCombinations = combinations;
                    combinations.clear();
                    if(!preCombinations.size()){
                        for(int i=0; i<3; i++){
                            string add = "";
                            add.append(1, 't'+i);
                            combinations.push_back(add);
                        }
                    }
                    else{
                        for(int j=0; j<preCombinations.size(); j++){
                            for(int i=0; i<3; i++){
                                string add = preCombinations[j];
                                add.append(1, 't'+i);
                                combinations.push_back(add);
                            }
                        }
                    }
                    break;
                case 9:
                    preCombinations = combinations;
                    combinations.clear();
                    if(!preCombinations.size()){
                        for(int i=0; i<4; i++){
                            string add = "";
                            add.append(1, 'w'+i);
                            combinations.push_back(add);
                        }
                    }
                    else{
                        for(int j=0; j<preCombinations.size(); j++){
                            for(int i=0; i<4; i++){
                                string add = preCombinations[j];
                                add.append(1, 'w'+i);
                                combinations.push_back(add);
                            }
                        }
                    }
                    break;
                default:
                    preCombinations = combinations;
                    combinations.clear();
                    if(!preCombinations.size()){
                        for(int i=0; i<3; i++){
                            string add = "";
                            add.append(1, 'a'+(digit-2)*3+i);
                            combinations.push_back(add);
                        }
                    }
                    else{
                        for(int j=0; j<preCombinations.size(); j++){
                            for(int i=0; i<3; i++){
                                string add = preCombinations[j];
                                add.append(1, 'a'+(digit-2)*3+i);
                                combinations.push_back(add);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return combinations;
    }
};
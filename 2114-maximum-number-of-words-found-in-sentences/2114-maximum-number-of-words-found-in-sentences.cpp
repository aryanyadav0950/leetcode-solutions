class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=0;
        for(int i=0;i<sentences.size();i++){
            int words=0;
            for(int j=0;j<sentences[i].size();j++){
                if(sentences[i][j]==' ') words++;
            }
            mx=max(words,mx);
        }
        return mx+1;
    }
};
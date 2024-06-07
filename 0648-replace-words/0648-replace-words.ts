function replaceWords(dictionary: string[], sentence: string): string {
    const sent = sentence.split(' ');
    const dict = new Set(dictionary);
    let lastIndex = sent.length - 1;
    let ans = "";
    for(let word of sent){
        let i = 0;
        while(i < word.length){
            let root = word.slice(0,i+1);
            if(dict.has(root)){
                ans += ` ${root}`;
                break;
            }
            else if(!dict.has(root) && i==word.length - 1){
                ans += ` ${word}`;
            }
            i++;
        }        
    }
    return ans.trim();
};
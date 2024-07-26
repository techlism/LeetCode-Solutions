function numUniqueEmails(emails: string[]): number {
    const unique = new Set();
    for(let email of emails){
        let divided = email.split('@');
        let local : string | string[] = divided[0].split('+');        
        let final = local[0].split('.').join('')+'@'+divided[1];
        unique.add(final);
    }
    return unique.size;
};
function numUniqueEmails(emails: string[]): number {
    const unique = new Set();
    for(let email of emails){
        let divided = email.split('@');
        let local : string | string[] = divided[0].split('+');
        local = local[0];
        local = local.split('.').join('');
        let final = local+'@'+divided[1];
        unique.add(final);
    }
    return unique.size;
};
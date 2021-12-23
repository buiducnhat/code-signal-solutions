function solution(a: string[]): string[] {
    a.sort((i,j)=>j.length - i.length);
    return a.filter(i=> {
        return (i.length === a[0].length);
    });
}

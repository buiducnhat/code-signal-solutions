function solution(votes: number[], k: number): number {
  let voteMax = Math.max(...votes);
  
  if (k === 0) {
      return votes.filter(vote=>vote === voteMax).length > 1 ? 0 : 1;        
  }
  
  return votes.filter(vote=>vote+k>voteMax).length;
}

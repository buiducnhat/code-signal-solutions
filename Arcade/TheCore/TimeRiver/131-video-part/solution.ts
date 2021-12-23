function reduce(numerator: number,denominator: number){
  const gcd = function gcd(a,b){
    return b ? gcd(b, a%b) : a;
  };
  const gcdRes = gcd(numerator,denominator);
  return [numerator/gcdRes, denominator/gcdRes];
}

function solution(part: string, total: string): number[] {
    const [ph, pm, ps] = part.split(':').map(Number);
    const [th, tm, ts] = total.split(':').map(Number);

    const totalPartSec = ph*3600+pm*60+ps;
    const totalSec = th*3600+tm*60+ts;
    
    console.log({totalPartSec, totalSec});
    return  reduce(totalPartSec, totalSec);
}

int solution(int n) {
  return ((n & 0b10101010101010101010101010101010) >> 1) 
       | ((n & 0b01010101010101010101010101010101) << 1) ;
}
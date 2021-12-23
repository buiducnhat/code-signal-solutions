bool solution(string fileName1, string fileName2) 
{
    string after1 = fileName1, after2 = fileName2;
    transform(after1.begin(), after1.end(), after1.begin(), ::tolower);
    transform(after2.begin(), after2.end(), after2.begin(), ::tolower);
    
    return (after1 < after2) != (fileName1 < fileName2);  
}

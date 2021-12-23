vector<string> solution(int levelNum, int levelHeight) {
    int height = 3 + levelHeight * levelNum + levelNum;
    int width = 2 * levelHeight + 3 + (levelNum - 1) * 2;

    // Generate matrix with fixed width & height
    vector<string> tree(height);

    // set for the crown
    tree[0].resize(width / 2 + 1, ' ');
    tree[1].resize(width / 2 + 1, ' ');
    tree[2].resize(width / 2 + 2, ' ');
    tree[0][width / 2] = tree[1][width / 2] = '*';
    tree[2][width / 2 - 1] = tree[2][width / 2] = tree[2][width / 2 + 1] = '*';

    // set for levels
    for (int level = 0; level < levelNum; level++) {
        // set for each row of level
        // row of tree = 3 + levelNum*level
        int row = 3 + levelHeight * level;
        for (int i = 0; i < levelHeight; i++) {
            tree[row + i].resize(width / 2 + i + 3 + level, ' ');
            for (int j = tree[row + i].size() - 1; j >= width / 2 - i - level - 2; j--) {
                tree[row + i][j] = '*';
            }
        }
    }

    // set for foot
    // set footLength, if even -> +1, odd: don't change
    int footLength = levelHeight + 1 - levelHeight % 2;
    for (int row = height - 1; row >= height - levelNum; row--) {
        tree[row].resize(width / 2 + 1 + footLength / 2, ' ');
        for (int i = tree[row].size() - 1; i >= width / 2 - footLength / 2; i--) {
            tree[row][i] = '*';
        }
    }

    return tree;
}

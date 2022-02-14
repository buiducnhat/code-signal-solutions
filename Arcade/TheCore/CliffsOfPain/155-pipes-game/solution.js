const solution = state => {
    const height = state.length;
    const width = state[0].length;
    
    // Find sources
    let sources = [];
    state.forEach((row, y) => {
        [...row].forEach((ch, x) => {
            if (ch >= 'a') {
                for (let dir = 0; dir < 4; dir++) {
                    sources.push([x, y, dir, ch.toUpperCase()]);
                }
            }
        });
    });
    
    // Pipe definitions
    // 0 = up, 1 = right, 2 = down, 3 = left
    const pipes = {
        1: {
            0: 0,
            2: 2,
        },
        2: {
            1: 1,
            3: 3,
        },
        3: {
            0: 1,
            3: 2,
        },
        4: {
            1: 2,
            0: 3,
        },
        5: {
            1: 0,
            2: 3,
        },
        6: {
            2: 1,
            3: 0,
        },
        7: {
            0: 0,
            1: 1,
            2: 2,
            3: 3,
        },
    };
    
    // Simulate the game
    let amount = 0;
    const filled = {};
    while (sources.length) {
        const nextSources = [];
        let hasLeaked = false;
        let addedAmount = 0;
        for (const [x, y, dir, target] of sources) {
            const [nx, ny] = [[x, y-1], [x+1, y], [x, y+1], [x-1, y]][dir];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                hasLeaked = true;
                continue;
            }
            const pipe = state[ny][nx];
            if (pipe in pipes) {
                if (dir in pipes[pipe]) {
                    const ndir = pipes[pipe][dir];
                    if (!filled[[nx, ny]]) {
                        filled[[nx, ny]] = true;
                        addedAmount++;
                    }
                    nextSources.push([nx, ny, ndir, target]);
                } else {
                    hasLeaked = true;
                }
            } else {
                hasLeaked = pipe !== target;
            }
        }
        if (hasLeaked && amount > 0) return -amount;
        amount += addedAmount;
        sources = nextSources;
    }
    return amount;
};
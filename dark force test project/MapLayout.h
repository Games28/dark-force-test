#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H
#include <string>


// level 0 - the blocks that are standing on ground level
std::string sMap_level0 =   // keep all the 1-9 and # cells unchanged. Replace all other non empty ones with #
//   0         1         2         3         4         5
//   0123456789012345678901234567890123456789012345678901
"##############.."
"#..............#"
"#..............#"
"#..............."
"#..............."
"#..............."
"#..............#"
"#..............#"
"#..............#"
"#.#............#"
"#..............#"
"#..............#"
"#..............#"
"#..............#"
"...............#"
".###.#####.####.";

std::string sMap_level1 =
//   0         1         2         3         4         5
//   0123456789012345678901234567890123456789012345678901
"#..............."
"................"
".......#.......Q"
"...............H"
"...............T"
"..........#....#"
"...............#"
"...............#"
"...............#"
"..##............"
"...............#"
"................"
"...............#"
"................"
"...............#"
"..##..##.######.";

std::string sMap_level2 =
//   0         1         2         3         4         5
//   0123456789012345678901234567890123456789012345678901
"#..............."
"................"
"................"
"................"
"..........#....."
"...............H"
"...............#"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"...####......#..";

std::string sMap_level3 =
//   0         1         2         3         4         5
//   0123456789012345678901234567890123456789012345678901
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"....##..........";

#endif // !MAPLAYOUT_H

std::string smap =

// tile layout of the map - must be of size nMapX x nMapY

   //            0         1         2         3
   //            01234567890123456789012345678901
    "............###................."
    ".*#########################....#"
    ".#............................##"
    ".#............................#."
    "##....................######..#."
    "##.....................#......@."
    ".#...@...........##.##.#...#..#."
    ".#...*@##................#.#..@."
    ".#...............##........#..#."
    ".#................####...###..@."
    ".#...#........................#."
    ".#.......*#.#*................@."
    ".#...@...#...#.......1........#."
    ".#.......#...#.......2........@."
    ".#...*....@@@........3........#."
    ".#...................#........@."
    ".#...-...............3........#."
    ".#...................2........@."
    ".#...+...............1........#."
    ".#............................@."
    ".#...=........................#."
    ".#.........1.2.3.#............@."
    ".#............................#."
    ".#............................@."
    ".#@*-+=..=+-*@#..#@*-+=..=+-*@#."
    ".#............................@."
    ".#............................#."
    ".#............................@."
    ".#............................#."
    "..............................@."
    "..#@*-+++===###.###===+++---***."
    "..............#.#..............."

    // Initialise fMap as a 2d array of floats, having the same size as sMap, and containing the height per cell.
    // NOTE - if MULTIPLE_LEVELS is false, the fMap will contain no values > 1
    // tile layout of the map - must be of size nMapX x nMapY

         //            0         1         2         3
         //            01234567890123456789012345678901
    "............###................."
    ".*#########################....#"
    ".#............................##"
    ".#..............Q.H.T.#.......@."
    ".#............................@."
    ".#............................@."
    ".#...................Q........@."
    ".#...................H........@."
    ".#...................T........@."
    ".#...................#........@."
    ".#...................T........@."
    ".#.......*#.#*.......H........@."
    ".#...@...#...#.......Q........#."
    ".#.......#...#................@."
    ".#...*....@@@.................#."
    ".#............................@."
    ".#...-..........1.............#."
    ".#...............2............@."
    ".#...+............3...........#."
    ".#.................4..........@."
    ".#...=..............5.........#."
    ".#.........1234......6........@."
    ".#............5.......7.......#."
    ".#.........9876........8......@."
    ".#......................9.....@."
    ".#.......................#....@."
    "..............................@."
    "..#@*-+++===#@*.*@#===+++---***."
    "..............#.#..............."
    "................................"
    "................................"
    "................................";

// Fastest solution among all
// High memory usage

class Solution {
    func numRookCaptures(_ board: [[Character]]) -> Int {
        let rook: Character = "R"
        let pawn: Character = "p"
        let bishop: Character = "B"
        let empty: Character = "."
        
        var dictionary: [Character: [(row: Int, column: Int)]] = [
            pawn: [],
            bishop: []
        ]
        var rookPosition: (row: Int, column: Int)? = nil
        var numberOfPawnsToBeCaptured = 0
        
        row: for i in 0..<board.count {
            column: for j in 0..<board[i].count {
                let piece = board[i][j]
                
                guard piece != empty else { continue }
                
                guard let position = rookPosition else {
                    if piece == pawn || piece == bishop {
                        dictionary[piece]!.append((i, j))
                    } else if piece == rook {
                        rookPosition = (i, j)
                    }
                    continue
                }
                
                // can only be bishop or pawn at this point
                if i == position.row {
                    numberOfPawnsToBeCaptured += piece == pawn ? 1 : 0
                    continue row
                } else if j == position.column {
                    // this is the last piece we need to check
                    numberOfPawnsToBeCaptured += piece == pawn ? 1 : 0
                    break row
                } else { continue }
            }
        }
        
        // check pieces of the same row as rook
        let squaresOfPawnAwayFromRookOfSameRow = dictionary[pawn]!.filter { $0.row == rookPosition!.row }.map { rookPosition!.column - $0.column }.min()
        let squaresOfBishopAwayFromRookOfSameRow = dictionary[bishop]!.filter { $0.row == rookPosition!.row }.map { rookPosition!.column - $0.column }.min()
        if squaresOfPawnAwayFromRookOfSameRow != nil {
            if squaresOfBishopAwayFromRookOfSameRow != nil {
                numberOfPawnsToBeCaptured += squaresOfPawnAwayFromRookOfSameRow! < squaresOfBishopAwayFromRookOfSameRow! ? 1 : 0
            } else {
                numberOfPawnsToBeCaptured += 1
            }
        }
        
        // check pieces of the same column as rook
        let squaresOfPawnAwayFromRookOfSameColumn = dictionary[pawn]!.filter { $0.column == rookPosition!.column }.map { rookPosition!.row - $0.row }.min()
        let squareOfBishopAwayFromRookOfSameColumn = dictionary[bishop]!.filter { $0.column == rookPosition!.column }.map { rookPosition!.row - $0.row }.min()
        if squaresOfPawnAwayFromRookOfSameColumn != nil {
            if squareOfBishopAwayFromRookOfSameColumn != nil {
                numberOfPawnsToBeCaptured += squaresOfPawnAwayFromRookOfSameColumn! < squareOfBishopAwayFromRookOfSameColumn! ? 1 : 0
            } else {
                numberOfPawnsToBeCaptured += 1
            }
        }
        
        // only outcomes: 0,1,2,3,4
        return numberOfPawnsToBeCaptured
    }
}

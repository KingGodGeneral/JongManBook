import Control.Monad

randoms :: Int -> [Int]
randoms seed = randoms' seed
    where randoms' s = let next = (s*15342 + 45194) `mod` 2384732 in next : randoms' next
-- Treap

data Tree a = Node a Int Int (Tree a) (Tree a) | Nil deriving Show

key :: Tree a -> a
key Nil = error "key Nil"
key (Node k _ _ _ _) = k

priority :: Tree a -> Int
priority Nil = error "priority Nil"
priority (Node _ p _ _ _) = p

size :: Tree a -> Int
size Nil = 0
size (Node _ _ s _ _) = s

left :: Tree a -> Tree a
left Nil = Nil
left (Node _ _ _ l _) = l

right :: Tree a -> Tree a
right Nil = Nil
right (Node _ _ _ _ r) = r


singleton :: (Ord a) => a -> Int -> Tree a
singleton k p = Node k p 1 Nil Nil

setLeft :: (Ord a) => Tree a -> Tree a -> Tree a
setLeft root l = Node (key root) (priority root) (1 + size l + size (right root)) l (right root)

setRight :: (Ord a) => Tree a -> Tree a -> Tree a
setRight root r = Node (key root) (priority root) (1 + size (left root) + size r) (left root) r

setLeftRight :: (Ord a) => Tree a -> Tree a -> Tree a -> Tree a
setLeftRight root l r = setRight (setLeft root l) r

split :: (Ord a) => Tree a -> a -> (Tree a, Tree a)
split Nil _ = (Nil, Nil)
split root k
    | key root < k = let (rl, rr) = split (right root) k in (setRight root rl, rr)
    | otherwise = let (ll, lr) = split (left root) k in (ll, setLeft root lr)

insert :: (Ord a) => Tree a -> Tree a -> Tree a
insert Nil  node = node
insert root node
    | priority root < priority node = let (l,r) = split root (key node) in setLeftRight node l r
    | key node < key root = setLeft root (insert (left root) node)
    | otherwise = setRight root (insert (right root) node)

merge :: (Ord a) => Tree a -> Tree a -> Tree a
merge Nil b = b
merge a Nil = a
merge a b
    | priority a < priority b = setLeft b (merge a (left b))
    | otherwise = setRight a (merge (right a) b)

delete :: (Ord a) => Tree a -> a -> Tree a
delete Nil _ = Nil
delete root k
    | key root == k = merge (left root) (right root)
    | k < key root = setLeft root (delete (left root) k)
    | otherwise = setRight root (delete (right root) k)

elemAt :: (Ord a) => Tree a -> Int -> a
elemAt root k
    | k <= size (left root) = elemAt (left root) k
    | k == size (left root) + 1 = key root
    | otherwise = elemAt (right root) (k - size (left root) - 1)

fromList :: (Ord a) => [a] -> Tree a
fromList keys = foldl (\acc x -> insert acc (uncurry singleton $ x)) Nil (zip keys priorities)
    where priorities = randoms 0

-- Problem
solve :: [Int] -> [Int]
solve moves = let (ans, _, _) = foldr fold ([],candidates,length moves) moves in ans
    where candidates = fromList [1..length moves]
          fold m (ans, cand, n) = let k = elemAt cand (n - m) in (k:ans, delete cand k, n-1)

solve' :: Int -> [Int] -> Tree Int -> [Int]
solve' _ [] _ = []
solve' n (m:moveR) candidates = k : solve' (n-1) moveR candidates'
    where k = elemAt candidates (1 + n - m)
          candidates' = delete candidates k

readInt :: IO Int
readInt = liftM read getLine

readInts :: IO [Int]
readInts = liftM (map read . words) getLine

print' ::(Show a) => a -> IO ()
print' = putStr . (++" ") . show

main :: IO ()
main = do
    c <- readInt
    let solveIO = readInt >> readInts >>= (\input -> mapM_ print' (solve input))
    forM_ [1..c] (\_ -> solveIO >> putStrLn "")

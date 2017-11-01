
prime :: fn (n: int) -> bool {
    if n < 2
        return true
    i := 2
    while i * i <= n {
        if n % i == 0
            return false
        i = i + 1
    }
    return true
}

i := 0
while i < 1000000 {
    prime(i)
    i += 1
}


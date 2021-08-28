package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
	"time"
)

type resultSet struct {
	numberOfSteps int
	inputNumbers []int64
}

func main() {
	args := os.Args
	if len(args) < 3 {
		return
	}
	start64, err := strconv.ParseInt(args[1], 10, 64)
	if err != nil {
		return
	}
	end64, err := strconv.ParseInt(args[2], 10, 64)
	if err != nil {
		return
	}
	results := make(map[int]*resultSet)
	highest := 0
	t1 := time.Now()
	for i := start64; i < end64; i++ {
		//log.Println(calculateCollatz(i))
		steps := calculateCollatz(i)
		res, ok := results[steps]
		if !ok {
			res = new(resultSet)
			res.numberOfSteps = steps
			res.inputNumbers = append(res.inputNumbers, i)
			results[steps] = res
			continue
		}
		res.inputNumbers = append(res.inputNumbers, i)
		if highest < steps {
			highest = steps
		}
	}
	t2 := time.Now()
	for _, set := range results {
		fmt.Println(set.numberOfSteps, len(set.inputNumbers))
	}
	log.Println(t2.UnixNano()-t1.UnixNano(), "   ", t2.Sub(t1).Milliseconds(), " highest steps count: ", highest, " with starting point/s: ", results[highest].inputNumbers)
}

func calculateCollatz(input int64) int {
	numberOfSteps := 0
	swap := input
	for swap != 1 {
		numberOfSteps++
		if swap%2 == 0 {
			swap = swap / 2
		} else {
			swap = (swap * 3) +1
		}
	}
	return numberOfSteps
}
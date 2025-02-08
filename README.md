# Exam Score Analyzer

This is a project that analyzes exam scores, calculates key statistics, and categorizes grades based on performance. It helps you assess overall student performance and allows you to save the results for future reference.

The way I programmed this project was by designing a system that takes in multiple exam scores, computes the average, and counts how many students scored above and below 50. I also implemented a grading system that categorizes scores into letter grades (A, B, C, D, F), making it easy to see the distribution of grades at a glance. Additionally, I included a feature to save the results to a text file, which was a great way to practice handling file operations.

I built this project because I wanted to create a practical tool for quickly analyzing student performance. It was an interesting challenge to structure the grading system properly while ensuring the program was easy to use. Hopefully, this makes exam score analysis more convenient and gives better insight into student performance trends.

## Example Output
```
--- Exam Score Analyzer ---
Enter exam scores (-1 to exit): 88 92 75 61 43 99 85 70 55 34 -1
The average exam score is: 70.20
Number of students with exam score >= 50: 7
Number of students with exam score < 50: 3

Grade Distribution:
A (90-100): 2
B (80-89): 2
C (70-79): 2
D (60-69): 1
F (<60): 3

Results saved to 'exam_results.txt'.

Would you like to analyze another set of scores? (y/n): n
Thank you for using the exam score analyzer!

```


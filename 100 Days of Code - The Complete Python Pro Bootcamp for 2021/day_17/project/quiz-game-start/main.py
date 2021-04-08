from question_model import Question
from data import question_data
from quiz_brain import QuizBrain


def bank():
    questions = list()
    for question in question_data:
        question_text = question["question"]
        question_answer = question["correct_answer"]
        questions.append(Question(question_text, question_answer))
    return questions


question_bank = bank()

quiz = QuizBrain(question_bank)

while quiz.still_has_question():
    quiz.next_question()
quiz.final_score()

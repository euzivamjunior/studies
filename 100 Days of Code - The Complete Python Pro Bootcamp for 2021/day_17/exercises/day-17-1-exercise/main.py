class User:

    def __init__(self, user_id, username):
        self.id = user_id
        self.username = username
        self.followers = 0
        self.following = 0

    def follow(self, user):
        user.followers += 1
        self.following += 1

    def report(self):
        print(f"{self.username} are following {self.following} users"
              f" and has {self.followers} followers")


user_1 = User("001", "angela")
user_2 = User("002", "jack")

user_1.follow(user_2)

user_1.report()
user_2.report()

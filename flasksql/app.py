from cs50 import SQL
from flask import Flask, render_template, request


app = Flask(__name__)
db = SQL("sqlite:///database.db")

SPORTS = [
    "BasketBall",
    "VolleyBall",
    "Football",
    "Cricket"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/registrants", methods=["POST"])
def reg():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or not sport:
        return render_template("failure.html")
    registrants = db.execute("SELECT * FROM users")
    db.execute("INSERT INTO users (name, sport) VALUES (?, ?)", name, sport)
    return render_template("registrants.html", registrants=registrants)
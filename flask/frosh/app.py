from flask import Flask, render_template, request

app = Flask(__name__)
REG ={}
SPORTS = [
    "cricekrt",
    "Football",
    "VolleyBall"
]
@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)
@app.route("/registered" , methods=["POST"])
def reg():
    name = request.form.get("hello")
    sport = request.form.get("sports")
    if not name:
        return render_template("failure.html")
    if sport not in SPORTS:
        return render_template("failure.html")
    REG[name] = sport
    return render_template("registered.html")

@app.route ("/registrants")
def regi():
    return render_template("registrants.html", registrants = REG)
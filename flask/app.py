from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        name = request.args.get("name", "World")
        return render_template("index.html", name=name)
    elif request.method == "POST":
        return render_template("question.html", name=request.form.get("name","World"))

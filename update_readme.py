import json

# Load stats
with open("stats.json", "r") as f:
    data = json.load(f)

stats = data["leetcode"]

# Load README
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# New stats string
new_stats = f"""
- 🟢 Easy: **{stats['easy']}**
- 🟡 Medium: **{stats['medium']}**
- 🔴 Hard: **{stats['hard']}**
- ✅ Total Solved: **{stats['solved']}**
"""

# Replace content between markers
start = "<!-- LC_STATS_START -->"
end = "<!-- LC_STATS_END -->"

before = content.split(start)[0] + start
after = end + content.split(end)[1]

updated_readme = before + "\n" + new_stats + "\n" + after

# Save back to README
with open("README.md", "w", encoding="utf-8") as f:
    f.write(updated_readme)

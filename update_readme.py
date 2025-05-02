import json

# Load stats
with open("stats.json", "r") as f:
    stats = json.load(f)

# Load README
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# Format new stats
new_stats = f"""
- 🟢 Easy: **{stats['easy']}**
- 🟡 Medium: **{stats['medium']}**
- 🔴 Hard: **{stats['hard']}**
"""

# Replace content between markers
start = "<!-- LC_STATS_START -->"
end = "<!-- LC_STATS_END -->"

before = content.split(start)[0] + start
after = end + content.split(end)[1]

updated_readme = before + "\n" + new_stats + "\n" + after

# Write updated content back
with open("README.md", "w", encoding="utf-8") as f:
    f.write(updated_readme)

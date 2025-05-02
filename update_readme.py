import json
import re

# Load LeetHub-generated stats
with open("stats.json", "r", encoding="utf-8") as f:
    stats = json.load(f)["leetcode"]

# Extract values
easy = stats.get("easy", 0)
medium = stats.get("medium", 0)
hard = stats.get("hard", 0)
solved = stats.get("solved", 0)

# Read the README
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# New stats block
stats_block = f"""<!-- LC_STATS_START -->
- 🟢 Easy: **{easy}**
- 🟡 Medium: **{medium}**
- 🔴 Hard: **{hard}**
- ✅ Total Solved: **{solved}**
<!-- LC_STATS_END -->"""

# Replace between markers
updated = re.sub(r"<!-- LC_STATS_START -->(.*?)<!-- LC_STATS_END -->", stats_block, content, flags=re.DOTALL)

# Write back
with open("README.md", "w", encoding="utf-8") as f:
    f.write(updated)

print("✅ Updated README with LeetCode stats.")

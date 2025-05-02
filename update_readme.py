import json
import re

# Step 1: Load the JSON data
with open("stats.json", "r", encoding="utf-8") as f:
    stats = json.load(f)

leetcode = stats.get("leetcode", {})
easy = leetcode.get("easy", 0)
medium = leetcode.get("medium", 0)
hard = leetcode.get("hard", 0)
solved = leetcode.get("solved", 0)

# Step 2: Load README
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# Step 3: Replace content between markers
pattern = r"<!-- LC_STATS_START -->(.*?)<!-- LC_STATS_END -->"
new_stats = f"""<!-- LC_STATS_START -->
- 🟢 Easy: **{easy}**
- 🟡 Medium: **{medium}**
- 🔴 Hard: **{hard}**
- ✅ Total Solved: **{solved}**
<!-- LC_STATS_END -->"""

# Step 4: Substitute the content
updated_content = re.sub(pattern, new_stats, content, flags=re.DOTALL)

# Step 5: Write back to README
with open("README.md", "w", encoding="utf-8") as f:
    f.write(updated_content)

print("✅ README.md updated successfully!")

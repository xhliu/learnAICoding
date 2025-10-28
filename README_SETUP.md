# Setting Up Automated Claude Code Reviews

This repository is configured to automatically review pull requests using Claude Code.

## Setup Instructions

### 1. Add Anthropic API Key to GitHub Secrets

1. Go to your repository on GitHub: https://github.com/xhliu/learnAICoding
2. Click **Settings** → **Secrets and variables** → **Actions**
3. Click **New repository secret**
4. Name: `ANTHROPIC_API_KEY`
5. Value: Your Anthropic API key (get one from https://console.anthropic.com/)
6. Click **Add secret**

### 2. How It Works

The workflow (`.github/workflows/claude-pr-review.yml`) will:
- Trigger automatically when a PR is opened, updated, or reopened
- Fetch the PR diff
- Send it to Claude API for review
- Post the review as a comment on the PR

### 3. What Claude Reviews

Claude will analyze:
- Summary of changes
- Potential bugs or issues
- Code quality assessment
- Security concerns
- Performance considerations
- Suggestions for improvement

### 4. Testing the Workflow

To test the automated review:
1. Create a new branch: `git checkout -b test-claude-review`
2. Make a small change to any file
3. Commit and push: `git push -u origin test-claude-review`
4. Create a PR on GitHub
5. Watch for Claude's review comment to appear

## Files Added

- `.github/workflows/claude-pr-review.yml` - GitHub Actions workflow
- `.github/PULL_REQUEST_TEMPLATE.md` - PR template with reminders

## Customization

You can customize the review prompt in the workflow file at line 39-55.

## Troubleshooting

- **No review appears**: Check that `ANTHROPIC_API_KEY` secret is set correctly
- **API errors**: Verify your API key has sufficient credits
- **Workflow doesn't run**: Check the Actions tab for error messages


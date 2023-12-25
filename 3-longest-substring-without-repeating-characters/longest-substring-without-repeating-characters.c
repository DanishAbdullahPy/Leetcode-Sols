int lengthOfLongestSubstring(char *s)
{
    // Create an array lastIndex to store the last index of every character.
    // Initialize all values in the array to -1.
    int lastIndex[256];
    for (int i = 0; i < 256; i++)
    {
        lastIndex[i] = -1;
    }

    // Initialize the maximum length substring without repeating characters
    // and the current length to 0.
    int maxLength = 0;
    int curLength = 0;

    // Iterate through the given string and find the maximum length substring
    // without repeating characters.
    for (int i = 0; s[i] != '\0'; i++)
    {
        // If the last index of the current character is not set or is
        // before the starting index of the current substring, increment
        // the current length.
        if (lastIndex[s[i]] == -1 || lastIndex[s[i]] < i - curLength)
        {
            curLength++;
        }
        // Otherwise, update the maximum length substring if necessary and
        // set the starting index of the current substring to the character
        // after the previous occurrence of the current character.
        else
        {
            if (curLength > maxLength)
            {
                maxLength = curLength;
            }
            curLength = i - lastIndex[s[i]];
        }

        // Update the last index of the current character.
        lastIndex[s[i]] = i;
    }

    // Update the maximum length substring if necessary.
    if (curLength > maxLength)
    {
        maxLength = curLength;
    }

    // Return the maximum length substring without repeating characters.
    return maxLength;
}

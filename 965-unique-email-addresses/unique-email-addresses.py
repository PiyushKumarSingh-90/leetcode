class Solution:
    def numUniqueEmails(self, emails):
        unique = set()

        for email in emails:
            local, domain = email.split("@")

            local = local.split("+")[0]
            local = local.replace(".", "")

            unique.add(local + "@" + domain)

        return len(unique)
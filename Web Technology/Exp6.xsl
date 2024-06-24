<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <!-- Template to match the root element -->
    <xsl:template match="/">
        <html>
            <head>
                <title>Address Book</title>
                <style>
                    table {
                        width: 100%;
                        border-collapse: collapse;
                    }
                    th, td {
                        border: 1px solid black;
                        padding: 8px;
                        text-align: left;
                    }
                    th {
                        background-color: #f2f2f2;
                    }
                </style>
            </head>
            <body>
                <h2>Address Book</h2>
                <table>
                    <tr>
                        <th>Name</th>
                        <th>Company</th>
                        <th>Phone</th>
                    </tr>
                    <!-- Apply templates to all address elements -->
                    <xsl:apply-templates select="addresses/address"/>
                </table>
            </body>
        </html>
    </xsl:template>

    <!-- Template to match each address element -->
    <xsl:template match="address">
        <tr>
            <td><xsl:value-of select="name"/></td>
            <td><xsl:value-of select="company"/></td>
            <td><xsl:value-of select="phone"/></td>
        </tr>
    </xsl:template>

</xsl:stylesheet>

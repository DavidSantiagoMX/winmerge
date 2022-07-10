/////////////////////////////////////////////////////////////////////////////
//    WinMerge:  an interactive diff/merge utility
//    Copyright (C) 1997  Dean P. Grimm
//    SPDX-License-Identifier: GPL-2.0-or-later
/////////////////////////////////////////////////////////////////////////////
// FilepathEdit.h : interface of the CFilepathEdit class
/** 
 * @file  FilePathEdit.h
 *
 * @brief Declaration file for CFilepathEdit class.
 */
#pragma once

#define EN_USER_CAPTION_CHANGED  0x0A01
#define EN_USER_FILE_SELECTED 0x0A02

/** 
 * @brief Read-only control to display a filepath. 
 * The path is compacted (with ellipsis) to fill in the area. 
 * The tooltip displays the entire path. 
 * ContextMenu offers two copy functions : copy path, copy filename
 */
class CFilepathEdit : public CEdit
{
public : 
	CFilepathEdit();

	bool SubClassEdit(UINT nID, CWnd* pParent);
	void RefreshDisplayText();
	const String& GetUpdatedTipText(CDC * pDC, int maxWidth);
	const String& GetSelectedFile() const { return m_sFilepath; };

	void SetActive(bool bActive);
	void SetOriginalText(const String& sString );
	void SetBackColor(COLORREF rgb);
	void SetTextColor(COLORREF rgb);
	void EnableFileSelection(bool enabled) { m_bEnabledFileSelection = enabled; }

protected:
	virtual BOOL PreTranslateMessage(MSG *pMsg);
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditCopy();
	HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	DECLARE_MESSAGE_MAP();

	void GetOriginalText( String& rString ) const;

private:
	void CustomCopy(size_t iBegin, size_t iEnd = String::npos);
	CRect GetMenuCharRect(CDC* pDC);

	String m_sToolTipString; /**< buffer for return data from GetUpdatedTipText */
	String m_sOriginalText; /**< Full path that was given to control */
	String m_sFilepath; /**< Selected file path */
	bool m_bActive; /**< Is the control active-looking? */
	COLORREF m_crText; /**< Control's text color. */
	COLORREF m_crBackGnd; /**< Control's background color. */
	CBrush m_brBackGnd; /**< Background brush for the control. */
	bool m_bInEditing;
	bool m_bEnabledFileSelection;
};

/**
 * @brief Return the control's original text.
 * @return Control's original text.
 */
inline void CFilepathEdit::GetOriginalText(String& rString) const
{		
	rString = m_sOriginalText;
}

